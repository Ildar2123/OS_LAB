#!/bin/bash

function switchOffNICViaIP(){
    NIC="$(ifconfig -a | grep -B3 "$1" | grep ":" | cut -f 1 -d ':')"
    printf "$(ip link set $NIC down)"
}

function about(){
   echo "Авторы (ИС-841): Хабибулин Ильдар"
   echo "Аргументы:"
   echo -e "\t2)--nic|-n - вывести информацию о сетевых интерфейсах"
   echo -e "\t  Пример: ./sys_net_sett_manag -n"
   echo -e "\t1)<up|down> <NIC> - включить/отключить сетевой(ые) интерфейс(ы)"
   echo -e "\t  Пример: ./sys_net_sett_manag wlp5s0 up ; или, если несколько ./sys_net_sett_manag up wlp5s0 down enp3s0"
   echo -e "\t3)-ip <NIC> <x.x.x.x> - установка IP адресса для сетевого интерфейса"
   echo -e "\t  Пример: ./sys_net_sett_manag -ip wlp5s0 192.169.0.202"
   echo -e "\t4)-m <NIC> <x.x.x.x> - установка netmask для сетевого интерфейса"
   echo -e "\t  Пример: ./sys_net_sett_manag -m wlp5s0 255.255.254.0"
   echo -e "\t5)-dl <IP> - отключение сетевого интерфейса по IP"
   echo -e "\t  Пример: ./sys_net_sett_manag -dl 192.168.0.59"
   echo -e "\t6)-kill <port ID> - убийство процесса по занимаемому порту"
   echo -e "\t  Пример: ./sys_net_sett_manag -kill 22"
}

#------------------------MAIN-----------------------------

if [ $# -lt 1 ]
then
    echo "Обязателен хотябы 1 параметр воспользуйтесь --help|-h"
    exit
fi

while [ -n "$1" ]
do
    case $1 in
    "-h" | "--help")
        about
        ;;
    "up" | "down")
        ACTION=$1 # up|down
        shift
        if [ -n "$(ifconfig -a | grep "$1: ")" ]
        then
            printf "$(ip link set $1 $ACTION)"
        else
            echo -en "\033[31m \nСетевого интерфейса $1 не существует \033[0m"
        fi
        ;;
    "-n" | "--nic")
        echo "$(ifconfig -a)"
        ;;
    "-ip")
        shift
        NIC=$1 # Имя сетевого интерфейса
        shift # Переходим к IP дрессу
        printf "$(ifconfig $NIC $1)"
        ;;
    "-m")
        shift
        NIC=$1 # Имя сетевого интерфейса
        shift # Переходим к netmask
        printf "$(ifconfig $NIC netmask $1)"
        ;;
    "-g")
        shift
        printf "$(ip route delete default)"
        printf "$(ip route add defult via $1)"
        ;;
    "-dl")
        shift # переход к IP адрессу порта
        switchOffNICViaIP $1
        ;;
    "-kill")
        shift # переходим к номеру порта
        printf "$(kill -9 $(sudo lsof -t -i:$1))"
        ;;
    *)
        echo "Неверная команда \"$1\""
    esac

    shift
done