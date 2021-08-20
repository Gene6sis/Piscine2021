cat /etc/passwd | sed '/^[[:blank:]]*#/d;s/#.*//' | sed -n 'n;p' | rev | cut -d ":" -f7 | sort -r | sed 's/$/, /' | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr -d '\n' | sed 's/..$/./' | tr -d '\n'
