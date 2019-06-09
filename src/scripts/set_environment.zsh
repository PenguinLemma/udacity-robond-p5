#!/bin/zsh
SCRIPTS_PATH="$( cd "$( dirname "${(%):-%x}" ) && pwd )"
export ROOT_HSR_REPO_PATH=$SCRIPTS_PATH/../..
MY_MODELS_PATH=$ROOT_HSR_REPO_PATH/src/world/model
source $ROOT_HSR_REPO_PATH/devel/setup.zsh
export GAZEBO_MODEL_PATH=$MY_MODELS_PATH:$GAZEBO_REPO_PATH
