alias c="clear"
alias sd="shutdown -h now"

#git aliases
alias gl="git log"
alias glp="git log --pretty=oneline"
alias gs="git status"
alias gb="git branch"
alias gc="git checkout"

aws_connect () {
	ssh -i "my-ec2.pem" ec2-user@ec2-34-226-140-120.compute-1.amazonaws.com
}

compile () {
  echo "Compiling your file : $1"
  g++ $1
  ./a.out
}



