## General Commands
1. lsblk<br>
    = Shows aprtitions

2. php -v<br>
    = Checks PHP status

3. lsb_release -a<br>
    = Shows the OS info.

4. su username<br>
    = Switch user

5. sudo apt install "program-name"<br>
    = Installs "program"

---

## Users & groups Management
1. sudo adduser "username"<br>
    = Creates a new user

2. sudo adduser "username" "group"<br>
    = Adds a user to to group

3. getent group "groupname"<br>
    = Lists users in a group
    = check everyone in a group

4. id -Gn "username"<br>
    = Shows groups a user belongs to

5. groups "username"<br>
    = Lists all groups a user is in

6. sudo groupadd "groupname"<br>
    = Creates a new group

---

## Hostname Management
1. hostname<br>
    = Displays current hostname

2. sudo hostnamectl set-hostname "new-hostname"<br>
    = Changes hostname without reboot

3. sudo nano /etc/hostname<br>
    = Modify hostname (but requires reboot)

---

## Passwords & security
1. sudo vim /etc/security/pwquality.conf<br>
    = Password policy settings

2. sudo vim /etc/login.defs<br>
    = Other password configurations

3. sudo -V<br>
   = Verifies if sudo is active

4. sudo vim /var/log/sudo/sudo.log<br>
    = Shows sudo activity logs

---

## Firewall management (UFW)
1. sudo ufw allow 8080<br>
    = Allows access to port 8080

2. sudo ufw status numbered<br>
    = Shows firewall rules with numbers

3. sudo ufw delete 5<br>
    = Deletes rule number #5

---

## SSH Configuration & Security
1. systemctl status sshd<br>
    = Checks SSH service status

2. sudo systemctl status ssh.service<br>
    = Verifies if SSH is active

3. sudo nano /etc/ssh/sshd_config<br>
    = View/modify SSH configuration

4. sudo "client-name" status sshd<br>
    = Checks "client" status for SSH

5. sudo tail -f /var/log/"client-name".log<br>
    = Monitors "clinet" logs

---

## Crontab (Scheduled Tasks)
1. crontab -e<br>
    = Opens the crontab editor (Command line)

2. sudo crontab -l<br>
    = Lists scheculed crontab settings.

3. sudo systemctl stop cron.service<br>
    = Stops cron service without deleting scripts.

---

## ETC
1. ip addr show
    = Displays the system's IP address

2. http://127.0.0.1:8080/
    = Localhost access for WordPress

3. sudo aa-status
    = Checks App Armor status

---

## Reference
1. DOWNLOAD DEBIAN<br>
    https://www.debian.org/

2. YOUTUBE: Follow one by one<br>
    https://www.youtube.com/watch?v=OQEdjt38ZJA

3. Detail<br>
    https://github.com/caroldaniel/42sp-cursus-born2beroot/blob/master/guides/Debian-en.md

4. Eval<br>
    https://github.com/PublioElio/School-42-Born2beroot#apparmor-application-armor

5. ETC<br>
    https://github.com/hanshazairi/42-born2beroot#installation
    https://github.com/HEADLIGHTER/Born2BeRoot-42/blob/main/evalknwoledge.txt
