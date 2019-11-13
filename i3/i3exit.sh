#!/bin/sh

lock() {
    letterEnteredColor=d23c3dff
    letterRemovedColor=d23c3dff
    passwordCorrect=00000000
    passwordIncorrect=d23c3dff
    background=00000000
    foreground=ffffffff
    i3lock-color \
	-n -i "/home/saagar/Pictures/whilte_lotus.png" \
	--datepos="tx+24:ty+25" \
	--clock --datestr "Type password to unlock..." \
	--insidecolor=$background --ringcolor=$foreground --line-uses-inside \
	--keyhlcolor=$letterEnteredColor --bshlcolor=$letterRemovedColor --separatorcolor=$background \
	--insidevercolor=$passwordCorrect --insidewrongcolor=$passwordIncorrect \
	--ringvercolor=$foreground --ringwrongcolor=$foreground \
	--radius=20 --veriftext="" --wrongtext="" \
	--textcolor="$foreground" --timecolor="$foreground" --datecolor="$foreground"
# --ring-width=4 
# --indpos="x+280:h-70" 
}

case "$1" in
    lock)
	i3lock -c 000000
        ;;
    logout)
        i3-msg exit
        ;;
    suspend)
        i3lock -c 000000
        systemctl suspend
        ;;
    hibernate)
	systemctl hibernate
        ;;
    reboot)
	reboot
        ;;
    shutdown)
        #dbus-send --system --print-reply --dest="org.freedesktop.ConsoleKit" /org/freedesktop/ConsoleKit/Manager org.freedesktop.ConsoleKit.Manager.Stop
        poweroff
        ;;
    *)
        echo "Usage: $0 {lock|logout|suspend|hibernate|reboot|shutdown}"
        exit 2
esac

exit 0
