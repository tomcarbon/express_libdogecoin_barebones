const express = require('express')
const app = express()
const {promisify} = require('util')
const exec = promisify(require("child_process").exec)

const port = 80;
const c_program_path = '../C/qkey'      


app.get('/privkey', async function (req, res) {
    try {
        // Call the C executable to grab the privkey/address pair.
        // The C program takes no input parameters and prints JSON to its stdout.
        const retval = await exec(`${c_program_path}`)
        const response = { "result": "success", "code": 200, "message": JSON.parse(retval.stdout.trim())}
        res.send(response)
    } catch (err) {
        const response = { "result": "failure", "code": 400, "message": err } 
        res.send(response)
    }
})

app.get('/', async function (req, res) {        
    // provide instructions if no endpoint was provided
    const response = { "result": "success", "code": 200, "message": "Use endpoint /privkey" } 
    res.send(response)
})

app.listen(port)
console.info(`C program path: ${c_program_path}.`)
console.info(`express/libdogecoin example program listening on port ${port}.`)