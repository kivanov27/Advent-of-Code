const fs = require('fs')
const readline = require('readline')

const path = './input.txt'
const fileStream = fs.createReadStream(path)
let sum = 0

const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
})

rl.on('line', line => {
    let first, last
    for (let x in line) {
       if (/[0-9]/.test(line[x])) {
           if (!first) {
               first = line[x]
           }
           else {
               last = line[x]
           }
       }
    }

    if (!last) {
        last = first
    }

    const two_digit_num = first + last
    
    if (two_digit_num) {
        sum += Number(two_digit_num)
    }

    console.log(`line: ${line}, num: ${two_digit_num}, sum: ${sum}`)
})

rl.on('close', () => {
    console.log(`sum: ${sum}`)
})
