
## sudo
- `/sbin/adduser username sudo`

## SSH
- `sudo service ssh restart`
- `sudo service ssh status`
- in `/etc/ssh/sshd_config` look for #Port 22 (change that and delete #)
- look for ports `ss -natp`
- `systemctl restart sshd`
- in `/etc/ssh/sshd_config`
- look for
- Port 4242
- PermitRootLogin

## Apparmor
- `sudo service apparmor status`

## Account
- `sudo adduser ...`
- `sudo deluser ...`

## UFW
- `sudo apt install ufw`
- `sudo ufw allow 4242`
- `sudo ufw enable`
- `sudo ufw disable`
- `sudo ufw status verbose`

## hostname
- `hostname`
- `sudo hostnamectl set-hostname max42`

## vi
- Insert mode - `i`
- command mode `Esc`
- delete one char `d`
- delete one word (to the right) `dw`
- save `:w!`
- quit `:q!`
- both `:wq!`

