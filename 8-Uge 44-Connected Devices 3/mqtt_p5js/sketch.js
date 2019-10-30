var shiftrkey = 'e4ac501e'; // key / username
var shiftrsecret = '1ea5eacc09ab0592'; // secret / password
var id = 'p5id' // client id
var client;

function setup() {

  // MQTT TING START
  // -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
  client = mqtt.connect('mqtt://' + shiftrkey + ':' + shiftrsecret + '@broker.shiftr.io', {

    id: 'p5id'
  });

  client.on('connect', function() {
    console.log('client has connected!');


    // HER SUBCRIBER VI TIL DE ADRESSER VI VIL LYTTE TIL
    // -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
    //client.subscribe('/hello');
    // client.unsubscribe('/example');
  });

  // HER FORTÆLLER VI AT VI VIL MODTAGE BESKEDERNE I VORES FUNKTION: messageReceived()
  // -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
  client.on('message', function(topic, message) {
    messageReceived(topic, message);
  });

  // -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
  // MQTT TING SLUT


  createCanvas(windowWidth, windowHeight);
  publishMessage('/hello', 'world');
}

function draw() {

}

// DEN HER FUNKTION KALDER VI NÅR VI VIL SENDE EN BESKED
function publishMessage(topic, message){
    client.publish(String(topic), String(message));
}

// DEN HER FUNKTION SKYDER HVER GANG VI MODTAGER EN BESKED
function messageReceived(t, m){
  var topic = t.toString();
  var message = m.toString();

  console.log('topic: ', topic, 'message: ', message);
}
