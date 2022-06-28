<template>
    <div class="docs">
      <h3 style="margin-top:20px;">Requirements</h3>
      <h5>Protocol</h5>
      <ul>
        <li>MQTT Over websockets - <span class="green">(broker: mosquitto)</span></li>
      </ul>
      <h5>Software</h5>
      <ul>
        <li>Arduino IDE - <span><a class="green" href="https://www.arduino.cc/en/software">download</a></span></li>
        <li>Visual Studio Code - <span><a class="green" href="https://code.visualstudio.com/download">download</a></span></li>
        <li>NPM & NodeJS - <span><a class="green" href="https://nodejs.org/en/download/">download</a></span></li>
        <li>XAMPP - <span><a class="green" href="https://www.apachefriends.org/">download</a></span></li>
        <li>PHP Composer - <span><a class="green" href="https://getcomposer.org/download/">download</a></span></li>
        <li>MQTTBox - <span><a class="green" href="https://chrome.google.com/webstore/detail/mqttbox/kaajoficamnjijhkeomgfljpicifbkaf?hl=id">download</a></span></li>
        <li>Postman - <span><a class="green" href="https://www.postman.com/downloads/">download</a></span></li>
      </ul>
      <h5>Database</h5>
      <ul>
        <li>MySQL - <span class="green">(PhpMyAdmin)</span></li>
      </ul>
      <h5>Framework</h5>
      <ul>
        <li>Laravel - <span class="green">(Web Services/REST API)</span></li>
        <li>Vuejs - <span class="green">(Front-end Web)</span></li>
        <li>NodeJS - <span class="green">(Back-end web)</span></li>
      </ul>
      <h5>Microcontroller</h5>
      <ul>
        <li>NodeMCU ESP8266</li>
      </ul>
      <h5>Sensor & Actuator</h5>
      <ul>
        <li>DHT11</li>
        <li>LED</li>
      </ul>
      <h3 style="margin-top: 20px;">Guides</h3>
      <h5>Arduino Source Code</h5>
        <vue-embed-gist 
            gist-id="4243b42dc8ad639e394640370d42fa55"
            file="leddht-mqttws.ino"/>
    </div>
</template>

<script>
import VueEmbedGist from '../Gist.js'

export default {
  components: {
    VueEmbedGist
  },
  data() {
    return {
      gistIdValue : '0c9be8f1974d126b38206380c9544592',
    }
  },
  methods: {
    changeGistId(){
      if(this.$data.gistIdValue === '0c9be8f1974d126b38206380c9544592'){
        this.$data.gistIdValue = 'f284fdc92dd66f8f16e6dee335ff3cef';
      }else{
        this.$data.gistIdValue = '0c9be8f1974d126b38206380c9544592';
      }
    }
  },
}
</script>

<!-- <style scoped>
.div-style {
  width: 50%;
  align-self: center;
  align-content:center;
  text-align: center;
  margin: 0 auto; 
}
</style> -->


<style>
@media (min-width: 1024px) {
  .docs {
    min-width: 100%;
    min-height: 100vh;
    align-items: center;
  }
}
</style>