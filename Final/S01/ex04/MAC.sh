ifconfig | grep ether | sed 's/ether//g' | tr -d "\f\t\r\v "

