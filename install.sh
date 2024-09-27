if [[ $(id -u) -ne 0 ]] ; then echo "Please run as root" ; exit 1 ; fi
sudo apt-get install -y libsdl2-dev
sudo apt-get install -y libsdl2-ttf-dev
sudo apt-get install -y libsdl2-mixer-dev
sudo apt-get install -y libsdl2-image-dev
./compile.sh
