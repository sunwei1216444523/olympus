#!/bin/bash

# 要检查的软件包列表
# 由于没有将项目放到docker中，所以需要提前先校验必要的第三方软件
packages=("libboost-all-dev" "libproj-dev" "zlib1g-dev" "libtinyxml2-dev" "libgoogle-glog-dev")

for package in "${packages[@]}"; do
    if dpkg -s "$package" | grep "install ok installed" >/dev/null 2>&1; then
        echo "$package is already installed."
    else
        echo "$package is NOT installed. "
        # echo "Attempting to install..."
        # sudo apt-get install -y "$package"
    fi
done