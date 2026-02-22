/*
Contains the HTML of the root page.
*/
static const char* RootPage = R"==(
<html>
<head>
  <title>Car controls</title>
  <style>
  #filldiv
  {
    height: 70vh;
    width: 90vw;
    display: flex;
    flex-direction: column;
    justify-content: center;
  }
  button
  {
    font-size: 60px;
  }
  #throttle{
    writing-mode: vertical-lr;
  }
  </style>
</head>
<body>
<div id="filldiv">
  <button type="button" id="turnLedOn">Turn led on</button>
  <button type="button" id="turnLedOff">Turn led off</button>
  <button type="button" id="toggleLed">Toggle led</button>
  <button type="button" id="motorForward">Motor forward</button>
  <button type="button" id="motorReverse">Motor reverse</button>
  <button type="button" id="motorStop">Motor stop</button>
  <button type="button" id="steerLeft">Steer left</button>
  <button type="button" id="steerStraight">Steer straight</button>
  <button type="button" id="steerRight">Steer right</button>

  <input type="range" min="0" max="180" step="10" id="steeringAngle"/>
  <input type="range" min="0" max="100" step="5" id="throttle"/>
</div>  
</body>

<script>
  document.getElementById("turnLedOn").addEventListener("click", () => fetch("/turnLedOn"));
  document.getElementById("turnLedOff").addEventListener("click", () => fetch("/turnLedOff"));
  document.getElementById("toggleLed").addEventListener("click", () => fetch("/toggleLed"));
  document.getElementById("motorForward").addEventListener("click", () => fetch("/motorForward"));
  document.getElementById("motorReverse").addEventListener("click", () => fetch("/motorReverse"));
  document.getElementById("motorStop").addEventListener("click", () => fetch("/motorStop"));
  document.getElementById("steerLeft").addEventListener("click", () => fetch("/steerLeft"));
  document.getElementById("steerStraight").addEventListener("click", () => fetch("/steerStraight"));
  document.getElementById("steerRight").addEventListener("click", () => fetch("/steerRight"));

  document.getElementById("steeringAngle").addEventListener("input", (event) => fetch(`/steeringAngle?value=${event.target.value}`));
  // TODO: dead mans switch: send request every second
  document.getElementById("throttle").addEventListener("input", (event) => fetch(`/throttle?value=${event.target.value}`));
</script>
</html>
)==";