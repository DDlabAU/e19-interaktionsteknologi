var key = 'try'; // key / username
var secret = 'try'; // secret / password
var client = 'id'


function setup() {

  // MQTT TING START
  // -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
  client = mqtt.connect('mqtt://' + key + ':' + secret + '@broker.shiftr.io', {
    clientId: client
  });

  client.on('connect', function() {
    console.log('client has connected!');


    // HER SUBCRIBER VI TIL DE ADRESSER VI VIL LYTTE TIL
    // -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
    client.subscribe('/etTopic');
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
