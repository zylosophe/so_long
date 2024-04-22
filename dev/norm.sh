#!/bin/zsh
setopt extendedglob
norminette -R CheckForbiddenSourceHeader ^(dev|mlx)
