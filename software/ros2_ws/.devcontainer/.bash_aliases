## Colorize the ls output ##
alias ls='ls --color=auto'
 
## Use a long listing format ##
alias ll='ls -la'
 
## Show hidden files ##
alias l.='ls -d .* --color=auto'

## get rid of command not found ##
alias cd..='cd ..'

## a quick way to get out of current directory ##
alias ..='cd ..'
alias ...='cd ../../../'
alias ....='cd ../../../../'
alias .....='cd ../../../../'
alias .4='cd ../../../../'
alias .5='cd ../../../../..'

## Colorize the grep command output for ease of use (good for log files)##
alias grep='grep --color=auto'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'

alias c='clear'

alias sha1='openssl sha1'

# install  colordiff package :)
alias diff='colordiff'

alias mount='mount |column -t'

# handy short cuts #
alias h='history'
alias j='jobs -l'
alias sleep='systemctl suspend'

# rpi robot aliases
alias ccb='colcon build --symlink-install'
alias teleopkb='ros2 run teleop_twist_keyboard teleop_twist_keyboard'
alias ros2simu='ros2 launch vacuum_bot launch_sim.launch.py'

#activate virtual environment for pio
alias pioenv='source ~/.platformio-env/bin/activate'
alias pioflash='pio run -t upload'
alias pioclean='pio run -t clean'
alias piorun='pio run'