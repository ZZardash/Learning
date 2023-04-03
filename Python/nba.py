#! /usr/local/bin/python3.11

import requests
from bs4 import BeautifulSoup

# Use requests to fetch the HTML page
r = requests.get('https://www.nba.com/players')

# Use BeautifulSoup to parse the HTML
soup = BeautifulSoup(r.text, 'html.parser')

# Find all player names on the page
player_names = soup.find_all('div', class_='RosterRow_playerName__G28lg')

# Print the names
for name in player_names:
    print(name.text)