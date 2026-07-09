const songs = [

{
    title:"Clair de Lune",
    artist:"Johann Debussy",
    src:"songs/song1.mp3",
    cover:"images/cover1.png"
},

{
    title:"Grandpa's Smoke",
    artist:"Pause, Maybe?",
    src:"songs/song2.mp3",
    cover:"images/cover2.png"
},

{
    title:"Fly me to the moon",
    artist:"Frank Sinatra",
    src:"songs/song3.mp3",
    cover:"images/cover3.png"
}

];

const audio = document.getElementById("audio");
const title = document.getElementById("title");
const artist = document.getElementById("artist");
const cover = document.getElementById("cover");
const playBtn = document.getElementById("playBtn");
const progress = document.getElementById("progress");
const volume = document.getElementById("volume");
const playlist = document.getElementById("playlist");

let currentSong = 0;

function loadSong(index){

    audio.src = songs[index].src;
    title.textContent = songs[index].title;
    artist.textContent = songs[index].artist;
    cover.src = songs[index].cover;

}

loadSong(currentSong);

function playPause(){

    if(audio.paused){
        audio.play();
        playBtn.innerHTML="⏸";
    }
    else{
        audio.pause();
        playBtn.innerHTML="▶";
    }

}

function nextSong(){

    currentSong++;

    if(currentSong>=songs.length)
        currentSong=0;

    loadSong(currentSong);
    audio.play();
    playBtn.innerHTML="⏸";

}

function prevSong(){

    currentSong--;

    if(currentSong<0)
        currentSong=songs.length-1;

    loadSong(currentSong);
    audio.play();
    playBtn.innerHTML="⏸";

}

audio.addEventListener("timeupdate",()=>{

    progress.max=audio.duration;

    progress.value=audio.currentTime;

    document.getElementById("current").textContent=format(audio.currentTime);

    document.getElementById("duration").textContent=format(audio.duration);

});

progress.addEventListener("input",()=>{

    audio.currentTime=progress.value;

});

volume.addEventListener("input",()=>{

    audio.volume=volume.value;

});

function format(time){

    if(isNaN(time)) return "0:00";

    let min=Math.floor(time/60);

    let sec=Math.floor(time%60);

    if(sec<10) sec="0"+sec;

    return min+":"+sec;

}

audio.addEventListener("ended",()=>{

    nextSong();

});

songs.forEach((song,index)=>{

    let li=document.createElement("li");

    li.textContent=song.title+" - "+song.artist;

    li.onclick=()=>{

        currentSong=index;
        loadSong(index);
        audio.play();
        playBtn.innerHTML="⏸";

    };

    playlist.appendChild(li);

});