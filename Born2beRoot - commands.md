
## sudo
- `/sbin/adduser USER sudo`

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
- `sudo adduser USER`
- `sudo deluser USER`
- `sudo groupadd GROUPNAME`
- list users: `cat /etc/passwd`
- list groups: `cat /etc/group`
- add to group: `sudo usermod -a -G USER GROUP`
- change to another user account: `su - USER`
- show groups: `groups`
- show groups USER belongs to: `groups USER`

## password policy
- change password: `passwd`
- show pw policy: `sudo cat /etc/shadow`  {userName}:{password}:{lastpasswdchanged}:{Minimum_days}:{Maximum_days}:{Warn}:{Inactive}:{Expire}:
- expiration of pw every 30 days (Max days): `sudo chage -M 30 USER`
- expiration of pw every 30 days (Min days): `sudo chage -m 30 USER`
- expiration of pw every 30 days (warn days): `sudo chage -W 30 USER`
- see pw policy: `sudo chage -l USER`

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

## system

- show partitions `lsblk`
