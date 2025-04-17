FROM ubuntu:22.04

# Install essential development tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    valgrind \
    git \
    vim \
    curl \
    wget \
    pkg-config \
    libncurses-dev \
    && rm -rf /var/lib/apt/lists/*

# Set up a non-root user (optional but recommended)
ARG USERNAME=dev
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Set the default user
USER $USERNAME

# Set the working directory
WORKDIR /workspace

# Set default command
CMD ["/bin/bash"]
