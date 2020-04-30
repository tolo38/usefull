## Summary
Docker is a system which is separate from the host but not like a virtual
machine cause it hasn't the overhead of having its own kernel. It has its
own isolated context.
The basic container files are in /opt

## Usage
### build an image
```
cd <path_to_docker_file>
docker build . -t <image_name>
```
Maybe need to run in sudo ?

### docker run 
```
# Basic run
docker run -it --user 1000 <build_env>
docker run -it --user 1000 stellargroup/build_env:ubuntu
```
`-it` means interactive and ...
`--user` is specifying normal user with the following uid

### Root privilege
```
# Run as root (to be able to apt install)
docker run -it --privileged <build_env>
```

### Mount to the our home dir
```
docker run -it -v=$HOME/projects/hpx_docker:/hpx/source -v $HOME/build/hpx_docker:/hpx/build stellargroup/build_env:ubuntu
```

### Open a new terminal on the same docker session
```
docker ps   # Showd the container id
docker exec -it <container_id> bash
```

### To add your local hidden files like .bashrc
Just mount your home dir
```
docker run -it --privileged -v=$HOME:/root <build_env>
```


### Often used
```
docker run -it --privileged -v=$HOME/projects/hpx_docker:/hpx/source \
    -v=$HOME/build/hpx_docker:/hpx/build stellargroup/build_env:ubuntu
```

### Remove stopped containers
```
docker system prune
```

### Useful options for gdb to work well in docker
```
docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined
```
