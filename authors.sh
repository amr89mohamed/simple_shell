#!/usr/bin/env bash
set -e

# Get the directory containing this script
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Get the author name of the latest commit
author_name="$(git log -1 --format='%aN' -- "$script_dir/$0")"

# Change to the directory containing the script
cd "$script_dir"

# Generate the AUTHORS file
{
    cat <<- 'EOH'
# This file lists all individuals having contributed content to the repository
# For how it is generated, see `generate-authors.sh`.

EOH
    echo "# Script Author"
    echo "$author_name"
    echo
    git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
