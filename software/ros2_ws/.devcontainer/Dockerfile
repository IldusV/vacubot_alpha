FROM ros:jazzy
ARG USERNAME=USERNAME
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Delete user if it exists in container (e.g Ubuntu Noble: ubuntu)
RUN if id -u $USER_UID ; then userdel `id -un $USER_UID` ; fi

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y \
    python3-pip \
    vim \
    libserial-dev \
    ros-jazzy-joy \
    ros-jazzy-teleop-twist-joy \
    ros-jazzy-twist-stamper \
    ros-jazzy-twist-mux \
    ros-jazzy-ros2-control \
    ros-jazzy-ros2-controllers \
    ros-jazzy-gz-ros2-control \
    ros-jazzy-teleop-twist-keyboard \
    ros-jazzy-slam-toolbox \
    ros-jazzy-ros2controlcli \
    ros-jazzy-ros-gz-bridge \
    ros-jazzy-xacro \
    ros-jazzy-ros-gz-sim \
    ros-jazzy-ros2-controllers-test-nodes \
    ros-jazzy-rviz2 && \
    apt-get clean && rm -rf /var/lib/apt/lists/*
    
ENV SHELL /bin/bash

COPY .bashrc /home/${USERNAME}/.bashrc
COPY .bash_aliases /home/${USERNAME}/.bash_aliases
RUN chown ${USERNAME}:${USERNAME} /home/${USERNAME}/.bashrc
RUN chown ${USERNAME}:${USERNAME} /home/${USERNAME}/.bash_aliases

# ********************************************************
# * Anything else you want to do like clean up goes here *
# ********************************************************

# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME
CMD ["/bin/bash"]
