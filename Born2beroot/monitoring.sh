
#!/bin/bash
arc=$(uname -a)
cpu=$(cat /proc/cpuinfo | grep "physical id" | sort | wc -l)
vcpu=$(grep "processor" /proc/cpuinfo | wc -l)
mem_percent=$(free -m | grep Mem | awk '{printf("%.2f", $3/$2*100)}')
mem=$(free -m | grep Mem | awk '{print $3 "/" $2 "MB" }')
disk_zaehler=$(df -BM | grep '^/dev' | grep -v '/boot' | awk '{used += $3} END {print used}')
disk_nenner=$(df -BG | grep '^/dev' | grep -v '/boot' | awk '{free += $2} END {print free "GB"}') 
disk_proc=$(df -BM | grep '^/dev' | grep -v '/boot' | awk '{used +=$3} {free +=$2} END {printf("%d", used/free*100)}')
cpu_load=$(top -bn1 | grep '^%Cpu' | awk '{printf("%s",$2 + $6)}')
boot=$(who -b | awk '{print $3 " " $4}')
lsblk=$(lsblk | grep lvm | wc -l)
lvm=$(if [ $lsblk -eq 0 ]; then echo no; else echo yes; fi)
tcp=$(cat /proc/net/sockstat | grep TCP: | awk '{print $3}')
log=$(who | wc -l)
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')
sudo=$(sudo journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "#Architecture: $arc
#CPU physical : $cpu
#vCPU : $vcpu
#Memory Usage: $mem ($mem_percent%)
#Disk Usage: $disk_zaehler/$disk_nenner ($disk_proc%)
#CPU load: $cpu_load%
#Last boot: $boot
#LVM use: $lvm
#Connections TCP : $tcp ESTABLISHED
#User log: $log
#Network: IP $ip ($mac)
#Sudo : $sudo cmd
"
exit 0

