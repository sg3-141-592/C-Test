FROM gitpod/workspace-full

USER gitpod

RUN sudo apt-get update -q && \
    sudo apt-get install -yq clang clang-tools libcpprest-dev boost-all-dev

