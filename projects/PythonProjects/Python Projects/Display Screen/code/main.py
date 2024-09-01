import os
import subprocess

print ('Hello, I am Danbot.. If you are new ask for help!') #intro

prompt = ">"     #sets the bit that indicates to input to >

input = raw_input (prompt)      #sets whatever you say to the input so bot can proces

raw_input (prompt)     #makes an input


if input == "help": #if the input is that
 print ('*****************************************************************') #says that
 print ('I am only being created.. more feautrues coming soon!') #says that
 print ('*****************************************************************') #says that
 print ('What is your name talks about names') #says that
 print ('Open (name of program) opens an application') #says that
 print ('sometimes a command is ignored.. restart me then!')
 print ('Also, once you type in a command, press enter a couple of times..')
 print ('*****************************************************************') #says that

raw_input (prompt)     #makes an input

if input == "open notepad": #if the input is that
 print ('opening notepad!!') #says that
 print os.system('notepad.exe') #starts notepad

if input == "open the internet": #if the input is that
 print ('opening firefox!!') #says that
 subprocess.Popen(['C:\Program Files\Mozilla Firefox\firefox.exe'])