<template>
    <div class="docs">
      <h3 style="margin-top:20px;">Demonstration</h3>
    <input
      class="input"
      type="text"
      @keydown.enter="handleSearch($event, 'youtube')"
      placeholder="Youtube Video Link or Video Id"
      :value="youtubeLink"
    />

    <LazyYoutube
      ref="youtubeLazyVideo"
      :src="youtubeLink"
      max-width="720px"
      aspect-ratio="16:9"
      thumbnail-quality="standard"
    />

    <div class="buttons">
      <button @click="handleClick('playVideo', 'youtubeLazyVideo')">
        Play
      </button>
      <button @click="handleClick('stopVideo', 'youtubeLazyVideo')">
        Stop
      </button>
      <button @click="handleClick('pauseVideo', 'youtubeLazyVideo')">
        Pause
      </button>
      <button @click="handleClick('resetView', 'youtubeLazyVideo')">
        Reset
      </button>
    </div>

    <h2>Pembuatan Web</h2>
    <h6>Menggunakan VueJs (Framework Javascript)</h6>
    <ul>
      <li>
      Installasi Vuejs: (<span class="green"><a href="https://github.com/vuejs/create-vue">panduan</a></span>)
      </li>
      <img src="@/assets/install-vue.png" alt="" width="600px">
      <br/><br/>
      <li>
      Tampilan Default Web Vuejs 2
      </li>
      <img src="@/assets/web-default.png" alt="" width="600px">
      <br/><br/><br/>
    </ul>
    <h6>Ngoding menggunakan Visual Studio Code (VSCode)</h6>
    <ul>
      <li>
        Tampilan VSCode
      </li>
      <img src="@/assets/tampilan-vscode.png" alt="" width="600px">
      <br/><br/>
      <li>
        Struktur Folder Vuejs
      </li>
      <img src="@/assets/folder-vue.png" alt="" width="600px">
      <br/><br/><br/>
    </ul>
    <h6>Membuat Tampilan Frontend Web Vuejs IoT</h6>
    <ul>
      <li>
        Ngoding Vuejs
      </li>
      <img src="@/assets/ngoding-vue.png" alt="" width="600px">
      <br/><br/>
      <li>
        Tampilan Web IoT
      </li>
      <img src="@/assets/web-jadi.png" alt="" width="600px">
      <br/><br/><br/>
    </ul>

    <h6>Pembuatan RESTful API Laravel (Backend)</h6>
    <ul>
      <li>
        cara Installasi laravel lihat bagian <span class="green">DOCS</span>
      </li>
      <br/>
      <li>
        Struktur Folder Laravel
      </li>
      <img src="@/assets/folder-laravel.png" alt="" width="600px">
      <br/><br/>
      <li>
        Hasil API
      </li>
      <img src="@/assets/hasil-API.png" alt="" width="600px">
      <br/><br/><br/>
    </ul>
    <h6>API Testing menggunakan Postman</h6>
    <ul>
      <img src="@/assets/API-testing.png" alt="" width="600px">
      <br/><br/><br/>
    </ul>

    <h2>Pembuatan Hardware</h2>
    <h6>Ngoding ESP8266 mengguanakan Arduino IDE</h6>
    <ul>
      <li>
        Arduino IDE
      </li>
      <img src="@/assets/arduino-ide.png" alt="" width="600px">
      <p>source code lihat pada bagian <span class="
      green">DOCS</span></p>
      <br/><br/>
      <li>
        Hardware
      </li>
      <img src="@/assets/hardware.png" alt="" width="600px">
      <br/><br/><br/>
    </ul>

    <h2>Database PhpMyAdmin (MySQL)</h2>
    <ul>
      <li>
        Tabel LED
      </li>
      <img src="@/assets/led-db.png" alt="" width="600px">
      <br/><br/>
      <li>
        Tabel DHT
      </li>
      <img src="@/assets/dht-db" alt="" width="600px">
      <br/><br/><br/>
    </ul>

    <!-- <h2>Vimeo Lazy Video</h2>
    <input
      class="input"
      type="text"
      @keydown.enter="handleSearch($event, 'vimeo')"
      placeholder="Vimeo Video Link"
      :value="vimeoLink"
    />

    <LazyVimeo
      ref="vimeoLazyVideo"
      :src="vimeoLink"
      max-width="720px"
      aspect-ratio="16:9"
      thumbnail-quality="standard"
    />

    <div class="buttons">
      <button @click="handleClick('playVideo', 'vimeoLazyVideo')">Play</button>
      <button @click="handleClick('stopVideo', 'vimeoLazyVideo')">Stop</button>
      <button @click="handleClick('pauseVideo', 'vimeoLazyVideo')">
        Pause
      </button>
      <button @click="handleClick('resetView', 'vimeoLazyVideo')">Reset</button>
    </div> -->
    </div>
</template>

<script>
export default {
  name: "Demo",

  data() {
    return {
      youtubeLink: "https://www.youtube.com/watch?v=TcMBFSGVi1c",
      vimeoLink: "https://player.vimeo.com/video/64654583",
    };
  },

  mounted() {
    // this.$refs['lazyVideo'].playVideo();
  },
  methods: {
    handleClick(event, ref) {
      this.$refs[ref][event]();
    },
    handleSearch(e, platform) {
      if (platform === "youtube") this.youtubeLink = e.target.value;
      else this.vimeoLink = e.target.value;
    },
  },
};
</script>

<style>
h2 {
  margin-bottom: 0;
  margin-top: 2rem;
}
.input {
  padding: 5px;
  max-width: 720px;
  margin-top: 25px;
  margin-bottom: 25px;
  width: 90%;
}

.buttons {
  margin-top: 25px;
}

@media (min-width: 1024px) {
  .docs {
    min-width: 100%;
    min-height: 100vh;
    align-items: center;
  }
}
</style>