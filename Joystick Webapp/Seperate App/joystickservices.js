window.addEventListener('load', () => {
    console.log("Testing");
    sendToESP32();
});

function sendToESP32(x,y) {
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "http://172.20.10.3/messageservice/async", true);
    xhr.setRequestHeader("Content-Type", "application/json");
    xhr.onreadystatechange = function() {
        if (xhr.readyState === 4 && xhr.status === 200) {
            console.log("Response from ESP32: " + xhr.responseText);
        }
    };
    xhr.send(JSON.stringify({'x':x,'y':y}));
    console.log(JSON.stringify({"x":x,"y":y}));
    
}