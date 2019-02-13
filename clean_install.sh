#!/bin/bash

nmcli d w r
nmcli d w > wifi.1
grep -o -E "University of Washington|~" wifi.1 > wifi.2
nmcli d w c "$(echo $(head -n 1 wifi.2))"

version=`cat /etc/*elease | tail -n 1 | cut -d'=' -f2`
uri="ubuntu.com/ubuntu/ $version main restricted universe multiverse"
echo "deb http://us.archive."$uri > /etc/apt/sources.list
echo "deb-src http://us.archive."$uri >> /etc/apt/sources.list
echo "deb http://security.ubuntu.com/ubuntu/" $version"-security main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb http://security.ubuntu.com/ubuntu/" $version"-updates main restricted" >> /etc/apt/sources.list

apt-get update
# add repositories
add-apt-repository -y ppa:wine/wine-builds
add-apt-repository -y ppa:webupd8team/atom
add-apt-repository -y ppa:caffeine-developers/ppa
add-apt-repository -y ppa:nathan-renniewaldock/flux
add-apt-repository -y ppa:deluge-team/ppa
apt-get update
# install files (yes there are a lot and something could break)
apt-get install -y binwalk bless caffeine xdotool wmctrl libinput-tools audacity chkrootkit chromium-browser debsums deluge emacs24 exif extundelete fluxgui foremost gimp john outguess testdisk virtualbox volatility wine1.6 wireshark dosbox xpdf radare2 atom netbeans openjdk-9-jdk dosemu openssl build-essential libssl-dev yasm libgmp-dev libpcap-dev pkg-config libbz2-dev
apt install -y git

# install libinput gestures
git clone http://github.com/bulletmark/libinput-gestures
cd libinput-gestures
./libinput-gestures-setup install
cd ..
rm -rf libinput-gestures

# configure libinput-gestures
libinput-gestures-setup start
libinput-gestures-setup autostart

# install google-play-music desktop
cd Downloads
wget https://github.com/MarshallOfSound/Google-Play-Music-Desktop-Player-UNOFFICIAL-/releases/download/v4.2.0/google-play-music-desktop-player_4.2.0_amd64.deb
# install packages
dpkg -i google-play-*.deb
# install uberwriter
dpkg -i uberwriter*.deb
apt-get -f install -y   # clean up uberwriter's dependencies

# install pycharm
echo "deb http://archive.getdeb.net/ubuntu $(lsb_release -cs)-getdeb apps" | sudo tee /etc/apt/sources.list.d/getdeb-apps.list
wget -q -O- http://archive.getdeb.net/getdeb-archive.key | sudo apt-key add -
apt-get update
apt-get -y install pycharm

# configure john the jumbo
cd /ctf/tools
git clone https://github.com/magnumripper/JohnTheRipper.git
cd John*
cd src
./configure && make
# leave dir
cd

# set up emacs
wget https://github.com/flyingmachine/emacs-for-clojure/archive/book1.zip
unzip book1.zi*
mv emacs-for-clojure-book1 ~/.emacs.d

# restore network-manager connections
cp -rf /home/system-connections /etc/NetworkManager/

# create a todo (to set up stuff)
printf "\nTODO:\nconfigure mouse,keyboard preferences\nflux:5000K,wallch:Pictures/backgrounds\natom_theme:onedark-base16-hopscotch-dark;atom-packages: base16-syntax,autocomplete-java-minus,busy,java-classpath-registry,java-import-wiz,java-plus,script\n"
# set up photoshop if possible

# clean up
rm book1.zi*
rm wifi.*
rm Downloads/google-play*.deb
