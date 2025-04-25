#-------------------------------------------------------------
# source environment files
#-------------------------------------------------------------

#. ${HOME}/.profile

#-------------------------------------------------------------
# Tailoring 'less'
#-------------------------------------------------------------

alias more='less'
export PAGER=less
export LESSCHARSET='latin1'

# LESS man page colors (makes Man pages more readable).
export LESS_TERMCAP_mb=$'\E[01;31m'
export LESS_TERMCAP_md=$'\E[01;31m'
export LESS_TERMCAP_me=$'\E[0m'
export LESS_TERMCAP_se=$'\E[0m'
export LESS_TERMCAP_so=$'\E[01;44;33m'
export LESS_TERMCAP_ue=$'\E[0m'
export LESS_TERMCAP_us=$'\E[01;32m'


# building prompt
#-------------------------------------------------------------

# Normal Colors
Black='\[\e[0;30m\]'        # Black
Red='\[\e[0;31m\]'          # Red
Red_B='\[\e[1;31m\]'        # Red Bold
Green='\[\e[0;92m\]'        # Green
Yellow='\[\e[0;33m\]'       # Yellow
Blue='\[\e[0;34m\]'         # Blue
Purple='\[\e[0;35m\]'       # Purple
Cyan='\[\e[0;36m\]'         # Cyan
#Cyan_B='\[\e[1;36m\]'       # Cyan Bold
White='\[\e[0;37m\]'        # White
NC_PR='\[\e[m\]'            # Color Reset
Blink='\[\e[5m\]'

export HOSTNAME=`hostname`
export USER_NAME=`whoami`

if [ ".$USER_NAME" == ".root" ];then
    LOGNAME="${Red_B}${LOGNAME}"
else
    LOGNAME="${Cyan_B}${LOGNAME}"
fi

DATE_PR="\D{%H}${Blink}:${NC_PR}\D{%M}"

export PS1="${Yellow}Docker[\w]${NC_PR}> "

#-------------------------------------------------------------
# Some settings
#-------------------------------------------------------------

# Disable options:
shopt -u mailwarn
unset MAILCHECK        # Don't want my shell to warn me of incoming mail.

#------------------------------------------------------------
# NMON 
#------------------------------------------------------------

export NMON=lmt


#------------------------------------------------------------
# History file config
#------------------------------------------------------------

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=10000
HISTFILESIZE=20000

#------------------------------------------------------------
# Other Custom stuff
#------------------------------------------------------------

# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

#------------------------------------------------------------------
# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.
#------------------------------------------------------------------
if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

#------------------------------------------------------------------
# custom variables
#------------------------------------------------------------------

source /opt/ros/jazzy/setup.bash
source install/setup.bash

