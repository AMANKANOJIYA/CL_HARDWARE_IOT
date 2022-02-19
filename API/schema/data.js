const mongoos = require('mongoose');
const schema = {
    datetime: {
        type: Date,
        default: Date.now
    },
    temperature: {
        type: Number,
    },
    humidity: {
        type:Number,
    },
    altitude: {
        type:Number,
    },
    pressure: {
        type:Number,
    }
}
module.exports  = mongoos.model("data", schema);