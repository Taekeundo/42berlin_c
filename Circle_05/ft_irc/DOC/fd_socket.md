[<back](<\<socket.h\>.md>) | [main](/)

---

## **Meaning of File Descriptors**
| **fd**  | **Meaning**                              | **Where does it come from?**          | **Behavior in `poll()`**             |
|--------|-------------------------------------------|----------------------------------------|--------------------------------------|
| **0**  | Standard Input (`stdin`)                  | Provided by the operating system       | Detects user input from the console  |
| **1**  | Standard Output (`stdout`)                | Provided by the operating system       | Not included in `poll()`             |
| **2**  | Standard Error Output (`stderr`)          | Provided by the operating system       | Not included in `poll()`             |
| **3**  | Server Socket                             | Created with `socket(AF_INET, SOCK_STREAM, 0)` | Listens for incoming connections     |
| **4**  | Client Socket                             | Created by `accept(server_fdsocket, ...)`     | Manages the connection to the client |
