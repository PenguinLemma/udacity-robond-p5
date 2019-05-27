1. Activate the right conda environment
It seems that `/root/.bashrc` is setting up conda to work with Python3. But the default version of python for `ros-kinetic` is `python2`. For that reason, we start a conda environment that was created for our nanodegree. 
Open a `Terminator` and write:
```shell
conda init bash
```
Close this terminal and open a new one. There, write:
```shell
conda activate /opt/robond/py2
```

Now the line in the terminal starts with `(/opt/robond/py2)`. Great! Stay in this terminal :)

2. Update/upgrade apt
```shell
sudo apt update && sudo apt upgrade -y
```

3. Go to your workspace
```
cd /home/workspace
```
4. Follow the rest of the [instructions](../README.md)
