sudo apt update
sudo apt install git

# Read the user input for github

echo "Enter the GitHub username: "  
read username  
git config --global user.name "$username"
 
echo "Enter the user GitHub Email: "  
read Email  
git config --global user.email "$Email"

# # Setup ssh for github

# ssh-keygen -t rsa -b 2048

# echo "copy the following key to 'SSH and GPG keys' in github settings :

# $(cat ~/.ssh/id_rsa.pub)"



