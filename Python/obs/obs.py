#! /usr/local/bin/python3.11

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.common.exceptions import NoSuchElementException
from selenium.common.exceptions import WebDriverException
from selenium.webdriver.support.wait import WebDriverWait
from pyvirtualdisplay import Display
from selenium.webdriver.support.ui import Select
from bs4 import BeautifulSoup
import requests
import urllib.request
import time
import sys

options = Options()
options.add_experimental_option("detach", True)
options.add_experimental_option("excludeSwitches", ["enable-automation"])
options.add_experimental_option("useAutomationExtension", False)

driver = webdriver.Chrome(
    options=options,
    executable_path=r"/usr/local/bin/chromedriver",
)

def check_exists(xpath):
    try:
        driver.find_element(By.XPATH, xpath)
    except NoSuchElementException:
        return False
    return True

def connection(host):
    try:
        urllib.request.urlopen(host)
        return True
    except:
        return False
    
    
def select_filter():
    # Select the "Land auswahlen" filter
    select = Select(driver.find_elements(By.CLASS_NAME, "dropdown-menu open"))
    select.select_by_visible_text("Deutschland")


try:
    driver.get("https://www.epal-pallets.org/eu-de/lizenznehmersuche")
    driver.implicitly_wait(10)
    select_filter()
        
except:
    while(connection == False):
        print("Trying again in 1 minute...")
        time.sleep(10)

    
    
     