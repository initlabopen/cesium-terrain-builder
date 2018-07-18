## -*- docker-image-name: "homme/cesium-terrain-builder:latest" -*-

##
# Cesium Terrain Builder
#
# This creates an image containing an installation of the Cesium Terrain
# Builder software (https://github.com/geo-data/cesium-terrain-builder).
#

FROM geodata/gdal:latest
MAINTAINER Homme Zwaagstra <hrz@geodata.soton.ac.uk>

# Install the application.
ADD . /usr/local/src/cesium-terrain-builder/
RUN /usr/local/src/cesium-terrain-builder/docker/build.sh

# Execute the gdal utilities as webmaster, not root
RUN useradd -d /home/webmaster -u 1000 -s /bin/bash -p qwerty123456 webmaster
USER webmaster

