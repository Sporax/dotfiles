# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, pkgs, ... }:

{
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
      ./aliases.nix
    ];

  # Use the systemd boot loader
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  # set luks devices
  boot.initrd.luks.devices = [
    {
      name = "root";
      device = "/dev/sda2";
      preLVM = true;  
    }
  ];

  networking.hostName = ""; # Define your hostname.
  networking.wireless.enable = true;  # Enables wireless support via wpa_supplicant.

  # Select internationalisation properties.
  i18n = {
    consoleFont = "Lat2-Terminus16";
    consoleKeyMap = "us";
    defaultLocale = "en_US.UTF-8";
  };

  # Set your time zone.
  time.timeZone = "America/Los_Angeles";

  # List packages installed in system profile. To search, run:
  #$ nix search wget
  environment.systemPackages = with pkgs; [
    wget vim
    macchanger
    glibcLocales
  ];

  # Some programs need SUID wrappers, can be configured further or are
  # started in user sessions.
  programs.bash.enableCompletion = true;
  # programs.mtr.enable = true;
  # programs.gnupg.agent = { enable = true; enableSSHSupport = true; };
  # disable the **damn annoying** ssh askpass -- makes git friendly
  programs.ssh.askPassword = "";

  # List services that you want to enable:
  
  # monitor scaling
  # yubikey
 # services.udev.packages = [ pkgs.yubikey-personalization ];
  services.udev.packages = [ pkgs.libu2f-host ];
  services.pcscd.enable = true;

  # Enable the OpenSSH daemon.
  # services.openssh.enable = true;

  # Open ports in the firewall.
  networking.firewall.allowedTCPPorts = [ 22 ];
  # networking.firewall.allowedUDPPorts = [ ... ];
  # Or disable the firewall altogether.
  # networking.firewall.enable = false;
  
  # openvpn configurations
  services.openvpn.servers = {
  };

  # Enable CUPS to print documents.
  # services.printing.enable = true;

  # sound.enable = true;
  # hardware.pulseaudio.enable = true;

  # Enable the X11 windowing system.
  environment.pathsToLink = [ "/libexec" ];
  services.xserver = {
    enable = true;
    layout = "us";
    
    monitorSection = ''
      DisplaySize 406 228
    '';

    # enable touchpad support
    libinput.enable = true;
    
    # desktopManager
    desktopManager = {
      default = "none";
      xterm.enable = false;
    };
    
    # enable i3
    windowManager.i3.enable = true;
    windowManager.default = "i3";
  };

  # enable brightness modification
  hardware.brightnessctl.enable = true;
  
  # Define a user account. Don't forget to set a password with ‘passwd’.
  users.extraUsers.nobody = {
    isNormalUser = true;
    uid = 1000;
    extraGroups = [ "wheel" "audio" "video" "input" "docker" ];
  };
  
  # Enable sound.
  sound.enable = true;
  hardware.pulseaudio = {
    enable = true;
    package = pkgs.pulseaudioFull;
  };
  
  # set fonts
  fonts = {
    enableFontDir = true;
    enableGhostscriptFonts = true;
    fonts = with pkgs; [
      dina-font
      inconsolata
      terminus_font
      proggyfonts
      dejavu_fonts
      font-awesome-ttf
      ubuntu_font_family
      source-code-pro
      source-sans-pro
      source-serif-pro
      emojione
    ];
  };

  # bluetooth
  hardware.bluetooth.enable = true;
  hardware.bluetooth.powerOnBoot = false;

  # virtualization
  virtualisation.libvirtd.enable = true;
  
  #nixpkgs.config.allowUnfree = true;
  virtualisation.virtualbox.host.enable = true;
  users.extraGroups.vboxusers.members = [ "nobody" ];
  #virtualisation.virtualbox.host.enableExtensionPack = true;
  virtualisation.docker.enable = true;

  # This value determines the NixOS release with which your system is to be
  # compatible, in order to avoid breaking some software such as database
  # servers. You should change this only after NixOS release notes say you
  # should.
  system.stateVersion = "19.09"; # Did you read the comment?
}
