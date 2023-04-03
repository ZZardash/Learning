#! /usr/local/bin/python3.11

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.common.exceptions import NoSuchElementException
from selenium.common.exceptions import WebDriverException
from selenium.webdriver.support.wait import WebDriverWait
from pyvirtualdisplay import Display
import urllib.request
import time
import sys

WINDOW_SIZE = "1920,1080"
options = Options()
options.add_experimental_option("detach", True)
options.add_experimental_option("excludeSwitches", ["enable-automation"])
options.add_experimental_option("useAutomationExtension", False)
options.add_argument("--headless")
options.add_argument("--window-size=%s" % WINDOW_SIZE)

driver = webdriver.Chrome(
    options=options,
    executable_path=r"/usr/local/bin/chromedriver",
)
usr = "sertac"
psw = "agungun1"

def check_exists(xpath):
    try:
        driver.find_element(By.XPATH, xpath)
    except NoSuchElementException:
        return False
    return True


#Modem Automation
def connection(host):
    try:
        urllib.request.urlopen(host)
        return True
    except:
        return False
    
def login(username, password):
    usr = driver.find_element(By.XPATH, "/html/body/div/div/div/form/label[1]/input")
    psw = driver.find_element(By.XPATH, '/html/body/div/div/div/form/label[2]/input')
    submit = driver.find_element(By.XPATH, "/html/body/div/div/div/form/input[3]")
    usr.send_keys(username)
    psw.send_keys(password)
    submit.click()
    
def logOut():
    logout = driver.find_element(By.XPATH, "/html/body/div/div/div/form/input")
    logout.click()
"""
def element(usr):
    usr.send_keys(usr)
"""    
try:
    driver.get("http://192.168.40.1/login")
    loggedOut = "/html/body/div/div/div/form/p"
    loggedIn = "/html/body/div/div/div/h1"
    if(check_exists(loggedIn)):       
        logOut()
        print("Logging Out.")
        driver.quit()
        
    if (check_exists(loggedOut)):
        login(usr, psw)
        print("Logged in.")
        driver.quit()
        
except:
    while (connection == False):
        print('Trying again in 1 minute')
        time.sleep(10)
