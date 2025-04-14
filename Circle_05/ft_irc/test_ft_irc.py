import socket
import threading
import time

SERVER = '127.0.0.1'  # IRC 서버 주소
PORT = 6667           # IRC 기본 포트
NICKNAME_PREFIX = 'testuser'

def simulate_user(user_id, channel="#testchannel", message="Hello from user", password="123"):
    try:
        nick = f"{NICKNAME_PREFIX}{user_id}"
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client.connect((SERVER, PORT))

        # 인증 순서: PASS → NICK → USER
        client.sendall(f"PASS {password}\r\n".encode())
        client.sendall(f"NICK {nick}\r\n".encode())
        client.sendall(f"USER {nick} 0 * :{nick}\r\n".encode())
        time.sleep(1)

        # 채널 접속 및 메시지 전송
        client.sendall(f"JOIN {channel}\r\n".encode())
        time.sleep(1)
        client.sendall(f"PRIVMSG {channel} :{message} {user_id}\r\n".encode())

        time.sleep(2)
        response = client.recv(4096).decode(errors="ignore")
        print(f"[{nick}] Response:\n{response}")

        client.sendall(b"QUIT\r\n")
        client.close()

    except Exception as e:
        print(f"[{user_id}] Error: {e}")

def run_test(user_count=5):
    threads = []
    for i in range(user_count):
        t = threading.Thread(target=simulate_user, args=(i,))
        t.start()
        threads.append(t)
        time.sleep(0.2)  # 약간의 딜레이로 동시 접속 시뮬레이션

    for t in threads:
        t.join()

if __name__ == "__main__":
    run_test()
