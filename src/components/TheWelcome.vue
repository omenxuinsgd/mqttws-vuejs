<script setup>
import WelcomeItem from './WelcomeItem.vue'
import DocumentationIcon from './icons/IconDocumentation.vue'
import ToolingIcon from './icons/IconTooling.vue'
import EcosystemIcon from './icons/IconEcosystem.vue'
import CommunityIcon from './icons/IconCommunity.vue'
import SupportIcon from './icons/IconSupport.vue'

// function publish1() {
//       this.$mqtt.publish("stiot/pub/led", "ON")
// }
</script>

<template>
  <div>
    <WelcomeItem>
      <template #icon>
        <DocumentationIcon />
      </template>
      <template #heading>Kontrol Lampu</template>
      <button class="btn btn-sm btn-outline-success" style="width: 100px; height:50px" @click="publish1">ON</button>
      <button class="btn btn-sm btn-outline-danger" style="width: 100px; height:50px" @click="publish2">OFF</button>
    </WelcomeItem>

    <WelcomeItem>
      <template #icon>
        <ToolingIcon />
      </template>
      <template #heading>Monitoring Suhu & Kelembapan</template>
      <div>
        <div class="example">
          <apexchart width="500" height="350" type="line" :options="chartOptions" :series="series"></apexchart>
        </div>
      </div>

    </WelcomeItem>

    <WelcomeItem>
      <template #icon>
        <EcosystemIcon />
      </template>
      <template #heading>Data Logging</template>
      <div class="card rounded shadow">
        <div class="card-header">DHT11 Data Logger</div>
        <div class="card-body">
          <table class="table">
            <thead>
              <tr>
                <th>Id</th>
                <th>Temperature</th>
                <th>Humidity</th>
                <th>Timestamp</th>
              </tr>
            </thead>
            <tbody>
              <tr v-for="course in courses.data.slice(0, 5)">
                <td>{{ course.id }}</td>
                <td>{{ course.temperature }}</td>
                <td>{{ course.humidity }}</td>
                <td>{{ course.created_at }}</td>
              </tr>
            </tbody>
            <router-link to="/dhtlogger" style="text-decoration: none;">Selengkapnya</router-link>
          </table>
        </div>
      </div>
    </WelcomeItem>

    <WelcomeItem>
      <template #icon>
        <CommunityIcon />
      </template>
      <template #heading>Receive Message</template>
      <div class="sub" v-html="buff">
      </div>
    </WelcomeItem>

    <WelcomeItem>
      <template #icon>
        <SupportIcon />
      </template>
      <template #heading>Support Me</template>

      As an independent project, Vue relies on community backing for its sustainability. You can
      help us by
      <a target="_blank" href="https://vuejs.org/sponsor/">becoming a sponsor</a>.
    </WelcomeItem>
  </div>
</template>

<style>
.sub {
  width: 100%;
  float: left;
  border: 1px solid #ccc;
  margin: 20px 1%;
  padding: 20px 0;
}
</style>

<!-- <script>
export default {
  methods: {
    publish1() {
      this.$mqtt.publish("stiot/pub/led", "ON")
    }
  },
  mqtt: {
    'stiot/pub/led' (data, topic) {
      console.log(topic + ': ' + String.fromCharCode.apply(null, data))
    }
  }
}
</script> -->

<script>
import axios from 'axios'

export default {
  mounted: function () {
    this.getCourses()
    console.log('mounted: got here')
  },
  data() {
    return {
      buff: 'Start:<br>',
      courses: [],
      task: {},
      chartOptions: {
        xaxis: {
          type: 'datetime',
          categories: ['01/01/2022', '02/01/2022','03/01/2022','04/01/2022','05/01/2022','06/01/2022','07/01/2022','08/01/2022'],
        },
      },
      series: [{
        name: 'Temperature(*C)',
        data: [30, 28, 27, 28, 25, 25, 26, 29]
      }, {
        name: 'Humidity(%)',
        data: [88, 90, 79, 77, 85, 80, 89, 86]
      }]
    }
  },
  created() {
    this.getCourses()
  },
  methods: {
    publish1() {
      this.$mqtt.publish("stiot/umeng/publish1", "ON")
    },
    publish2() {
      this.$mqtt.publish("stiot/umeng/publish1", "OFF")
    },
    getCourses: function () {
      var self = this
      const url = 'https://leddht-api-iot.herokuapp.com/api/v1/umeng/dht'
      axios.get(url, {
        dataType: 'json',
        headers: {
          'Accept': 'application/json',
          'Content-Type': 'application/json'
        },
        mode: 'no-cors',
        credentials: 'include'
      })
        .then(function (response) {
          console.log(JSON.stringify(response.data))
          self.courses = response.data
        })
        .catch(function (error) {
          console.log(error)
        })
    },
    generateDayWiseTimeSeries(baseval, count, yrange) {
        var i = 0;
        var series = [];
        while (i < count) {
          var x = baseval;
          var y = Math.floor(Math.random() * (yrange.max - yrange.min + 1)) + yrange.min;
          series.push([x, y]);
          baseval += 86400000;
          i++;
        }
        return series;
      },
      updateChart() {
        let series = [
            {
            name: 'South',
            data: this.generateDayWiseTimeSeries(new Date('11 Feb 2017').getTime(), 20, {
              min: 10,
              max: 60
            })
          },
          {
            name: 'North',
            data: this.generateDayWiseTimeSeries(new Date('11 Feb 2017').getTime(), 20, {
              min: 10,
              max: 20
            })
          },
          
          {
            name: 'Central',
            data: this.generateDayWiseTimeSeries(new Date('11 Feb 2017').getTime(), 20, {
              min: 10,
              max: 15
            })
          }
        ]
        this.series = series
      }
  },
  mqtt: {
    'stiot/umeng/+'(data, topic) {
      if (topic.split('/').pop() === 'publish1') {
        let msg = { 'status': String.fromCharCode.apply(null, data) }
        axios.put(
          `https://leddht-api-iot.herokuapp.com/api/v1/umeng/led/1`, msg
        )
      }
      if (topic.split('/').pop() === 'dht') {
        let uri = 'https://leddht-api-iot.herokuapp.com/api/v1/umeng/dht';
        let dhtString = String.fromCharCode.apply(null, data)
        let dhtParse = JSON.parse(dhtString.toString())
        console.log(dhtParse)

        axios.post(uri, dhtParse)
          .then(response => {
            this.courses = response.data;
            this.getCourses()   // you need to call your api again, here, to fetch the latest results after successfully adding a new task
          })
          .catch(error => {
            if (error.response.status == 422) {
              this.errors = error.response.data.errors;
            }
          });
      }
      this.buff = this.buff + "topic: " + topic + ", message: " + data + '<br>'
    }
  },
}
</script>