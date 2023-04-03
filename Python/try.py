import os
import pyinstaller
from selenium import webdriver

os.environ["PATH"] += "C:/SeleniumDrivers"
driver = webdriver.Chrome()


