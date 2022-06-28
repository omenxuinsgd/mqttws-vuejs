<template>
    <div class="dht" style="margin-top: 20px;">
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
              <tr v-for="course in courses.data">
                <td>{{ course.id }}</td>
                <td>{{ course.temperature }}</td>
                <td>{{ course.humidity }}</td>
                <td>{{ course.created_at }}</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
    </div>
</template>

<style>
@media (min-width: 1024px) {
  .dht {
    min-width: 100%;
    min-height: 100vh;
    display: flex;
    align-items: center;
  }
}
</style>

<script>
import axios from 'axios'

export default {
  mounted: function () {
    this.getCourses()
    console.log('mounted: got here')
  },
  data() {
    return {
      courses: [],
      task: {}
    }
  },
  created() {
    this.getCourses()
  },
  methods: {
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
    }
  }
}
</script>