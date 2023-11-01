### 连接wifi

```sh
iwctl 
station wlan0 connect linzui
exit
```

### 换源

```sh
vim /etc/pacman.d/mirrorlist
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
```

### 分区

```sh
cfdisk /dev/nvme0n1
mkfs.fat -F32 /dev/nvme0n1p1
mkswap /dev/nvme0n1p2
mkfs.ext4 /dev/nvme0n1p3
```

### 挂载分区

```sh
mount /dev/nvme0n1p3 /mnt
swapon /dev/nvme0n1p2
mkdir /mnt/boot
mount /dev/nvme0n1p1 /mnt/boot
```

### 安装基本系统

```sh
pacstrap /mnt base base-devel linux linux-firmware linux-headers vim intel-ucode networkmanager

genfstab -U /mnt >> /mnt/etc/fstab
arch-chroot /mnt
```

### 修改主机名

```sh
echo "LAPTOP-EV6AO0H2" >> /etc/hostname

vim /etc/hosts
127.0.0.1   localhost
::1         localhost
127.0.1.1   arch.localdomin     LAPTOP-EV6AO0H2
```

### 新建用户并设置密码

```sh
passwd
useradd -mG wheel linzui
passwd linzui
visudo
```

### 安装引导程序

```sh
vim /etc/fstab
fmask=0137,dmask=0027

umount /boot
mount /boot

bootctl install
```

### 引导程序基本设置

```sh
vim /boot/loader/loader.conf
default arch-*

vim /boot/loader/entries/arch.conf
title    Arch Linux
linux    /vmlinuz-linux
initrd    /intel-ucode.img
initrd    /initramfs-linux.img
options    root=/dev/nvme0n1p3 rw quiet loglevel=3 rd.udev.log_level=3 systemd.show_status=auto vt.global_cursor_default=0 i915.fastboot=1
```

### 启用网络

```sh
systemctl enable NetworkManager
```

### 重启进入系统

```sh
exit
umount -a
reboot
```

### 安装基本kde环境

```sh
sudo pacman -S wayland plasma sddm plasma-wayland-session
sudo systemctl enable sddm
sudo pacman -S ark kfind kcalc spectacle kate gwenview kamoso konsole dolphin
```

### 音量管理器

```sh
sudo pacman -S sof-firmware
```

### 安装paru clash

```sh

```

### 小设置

```sh
vim /etc/mkinitcpio.conf 
udev -> systemd
paru -S upd72020x-fw ast-firmware aic94xx-firmware wd719x-firmware
sudo pacman -S linux-firmware-qlogic

mkinitcpio -P
bootctl update
```

### 安装中文输入法

```sh
sudo pacman -S fcitx5 fcitx5-chinese-addons fcitx5-im fcitx5-configtool fcitx5-qt fcitx5-gtk fcitx5-lua

sudo vim /etc/environment
GTK_IM_MODULE=fcitx
QT_IM_MODULE=fcitx
XMODIFIERS=@im=fcitx
```

### 安装蓝牙

```sh
sudo pacman -S bluez bluez-utils pulseaudio-bluetooth
sudo systemctl enable bluetooth.service
```

