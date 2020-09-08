FROM ubuntu:20.04
MAINTAINER "Iordanis Kostelidis <kostelidis@ieee.org>"

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ="Europe/Athens"

RUN apt-get update \
 && apt-get install -y \
                automake \
                build-essential \
                cmake \
                make \
 && apt-get clean \
 && apt-get autoclean

ARG UID=1000
ARG GID=1000
ARG USERNAME="user"

RUN groupadd -r "${USERNAME}" -g "${GID}" \
 && useradd -ms /bin/bash "${USERNAME}" -u "${UID}" -g "${GID}"

USER "${USERNAME}"
WORKDIR /home/"${USERNAME}"