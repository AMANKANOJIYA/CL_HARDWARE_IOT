require('dotenv').config()
const express = require('express');
const mongoose = require("mongoose");
const dataModel = require("./schema/data");
const app = express();


// mongoose connection-------------------------------------------------------
mongoose.connect(process.env.URL, { useNewUrlParser: true, useUnifiedTopology: true });
const con = mongoose.connection;
con.on("open", () => {
  console.log("Connected ........");
});

app.get("/senddata", async (req, res) => {
  var temp = req.query.temp;
  var hum = req.query.hum;
  var alt = req.query.alt;
  var pres = req.query.pres;
  const Data = await dataModel({
    temperature: temp,
    humidity: hum,
    altitude: alt,
    pressure: pres
  });
  await Data.save();
  res.sendStatus(200);
})


app.listen(process.env.PORT, process.env.HOSTNAME, function() {
  console.log(".............................................");
});