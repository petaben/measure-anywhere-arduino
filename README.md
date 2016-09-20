##Arduino GSM

###Serial
To show serial console in OSX: ``screen /dev/cu.usbmodem1411 9600``

###Nexmo API
sms:
````
curl -X POST -H "Content-Type: application/json" -d '{
    "api_key": <key>,
    "api_secret": <secret>,
    "from": "MyApp",
    "to": <phone number>,
    "text": "Bonjour"
}' "https://rest.nexmo.com/sms/json"
````
text to speech call:
````
curl -X POST -H "Content-Type: application/json" -d '{
    "api_key": <key>,
    "api_secret": <secret>,
    "to": <phone number>,
    "text": "Bonjour"
}' "https://api.nexmo.com/tts/json"
````

###TODO
- make HTTP POST inside loop
