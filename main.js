const {app, BrowserWindow } = require("electron");
const lib = require("bindings")("lib");
let win;

function createWindow(){
    win = new BrowserWindow({
        width: 500,
        height: 500,
        frame: false,
        transparent: true
    });
    win.loadFile("index.html");
    lib.setup(win.getNativeWindowHandle());
}

app.on("ready", createWindow);