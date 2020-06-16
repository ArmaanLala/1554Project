const electron = require('electron');
const url = require('url')
const path = require('path')

const {app,BrowserWindow,Menu} = electron;

let mainWindow;

// Listen for electron app

app.on('ready',function(){

    //Create new window
//width:1920,height:1080,fullscreen: false
    mainWindow = new BrowserWindow({});
    // Load html file
    mainWindow.loadURL(url.format({
        pathname: path.join(__dirname,'index.html'),
        protocol:'file:',
        slashes:true
    }));

    // Build Menu
    const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);
    //Insert Menu
    Menu.setApplicationMenu(mainMenu);
    // mainWindow.webContents.openDevTools();
    // mainWindow.setResizable(false);
    // mainWindow.setFullScreen(false);
});

const mainMenuTemplate = [
    {
        label:'File',
        submenu:[
            {
            label:'Restart',
            click() {
                mainWindow.reload();
            }
            },
            {
                label:'Quit',
                click(){
                    app.quit();
                }
            }
        ]
    }
];