# ED3
Source code for delta robot

## MATLAB App Designer
- Go to function sendToESP32(app)
- Change the IP or URL to your network's IP -> 'http://{your_IP}/messageservice/async'

## MATLAB Web App Server
- First, generate a web app file:
  + Designer -> Share -> Web App -> Select open output folder
  + .ctf should appear inside the pop-up folder
- Then, open MATLAB Web App Server:
  + Stop the server if it is running
  + Choose Open App Folder
  + Drag the .ctf file in first step into this folder
  + Start the server
  + Go to localhost:9988 to confirm the server has started
