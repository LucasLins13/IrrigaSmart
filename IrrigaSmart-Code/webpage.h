#ifndef WEBPAGE_H
#define WEBPAGE_H

const char HTML_PAGE[] PROGMEM = R"rawhtml(
<!DOCTYPE html>
<html lang="pt-BR">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>IrrigaSmart</title>
<style>
*,*::before,*::after{box-sizing:border-box;margin:0;padding:0}
:root{
  --bg:#0e0e0e;
  --card:#1a1a1a;
  --card2:#1f1f1f;
  --border:#2a2a2a;
  --text:#eaeaea;
  --muted:#8a8a8a;
  --green:#4ade80;
  --red:#f87171;
  --amber:#fbbf24;
  --blue:#60a5fa;
  --purple:#a78bfa;
  --mono:ui-monospace,'SF Mono',Consolas,monospace;
}
html,body{background:var(--bg);color:var(--text);font-family:-apple-system,Segoe UI,Roboto,sans-serif;font-size:15px}
body{padding:16px;max-width:760px;margin:0 auto}

header{display:flex;justify-content:space-between;align-items:baseline;margin-bottom:14px;padding-bottom:12px;border-bottom:1px solid var(--border)}
h1{font-size:1.1em;font-weight:600}
h1 span{color:var(--green)}
#clock{font-family:var(--mono);font-size:.8em;color:var(--muted)}

/* ── ABAS ── */
.tabs{display:flex;gap:4px;margin-bottom:16px;overflow-x:auto;padding-bottom:2px}
.tab-btn{
  flex-shrink:0;background:var(--card);border:1px solid var(--border);color:var(--muted);
  padding:8px 14px;border-radius:8px;font-size:.82em;font-weight:600;cursor:pointer;
  font-family:inherit;white-space:nowrap;transition:all .15s;
}
.tab-btn.active{background:var(--green);color:#0e0e0e;border-color:var(--green)}
.tab-btn:not(.active):hover{color:var(--text);border-color:#3a3a3a}

.tab-pane{display:none}
.tab-pane.active{display:block}

.grid{display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-bottom:16px}
.box{background:var(--card);border:1px solid var(--border);border-radius:10px;padding:14px}
.box .label{font-size:.7em;text-transform:uppercase;letter-spacing:.06em;color:var(--muted);margin-bottom:6px}
.box .val{font-family:var(--mono);font-size:1.6em;font-weight:600}
.box .sub{font-size:.75em;color:var(--muted);margin-top:4px}
.v-green{color:var(--green)} .v-red{color:var(--red)} .v-amber{color:var(--amber)} .v-blue{color:var(--blue)}

section{background:var(--card);border:1px solid var(--border);border-radius:10px;padding:16px;margin-bottom:14px}
section h2{display:flex;justify-content:space-between;align-items:center;font-size:.85em;text-transform:uppercase;letter-spacing:.05em;color:var(--muted);margin-bottom:12px;font-weight:600}
.count-badge{font-family:var(--mono);font-size:.75em;background:var(--card2);border:1px solid var(--border);padding:2px 8px;border-radius:99px;color:var(--text);text-transform:none;letter-spacing:0}

.pump{display:flex;align-items:center;justify-content:space-between;gap:10px;margin-bottom:10px}
.pump-info{font-size:.85em;color:var(--muted)}
.pump-info b{color:var(--text);display:block;font-size:1.1em}
button{
  border:none;border-radius:8px;padding:11px 18px;font-size:.9em;font-weight:600;
  cursor:pointer;font-family:inherit;color:#0e0e0e;
}
.btn-on{background:var(--red);color:#fff}
.btn-off{background:var(--green)}
button:active{opacity:.8}

.alert{font-size:.8em;padding:8px 10px;border-radius:7px;margin-top:8px}
.alert-temp{background:rgba(248,113,113,.12);color:var(--red)}
.alert-hum{background:rgba(96,165,250,.12);color:var(--blue)}
.alert-ok{background:rgba(74,222,128,.12);color:var(--green)}

.table-wrap{overflow-x:auto}
table{width:100%;border-collapse:collapse;font-size:.82em}
th{text-align:left;color:var(--muted);font-weight:600;font-size:.72em;text-transform:uppercase;padding:6px 8px;border-bottom:1px solid var(--border);white-space:nowrap}
td{padding:7px 8px;border-bottom:1px solid var(--border);font-family:var(--mono);white-space:nowrap}
tr:last-child td{border-bottom:none}
.empty{text-align:center;color:var(--muted);font-size:.85em;padding:24px}
.badge-auto{background:rgba(74,222,128,.15);color:var(--green);padding:2px 7px;border-radius:99px;font-size:.78em}
.badge-manual{background:rgba(251,191,36,.15);color:var(--amber);padding:2px 7px;border-radius:99px;font-size:.78em}

/* ── MINI CHART ── */
.chart{height:120px;display:flex;align-items:flex-end;gap:2px;overflow-x:auto;border-bottom:1px solid var(--border);padding-bottom:2px;margin-bottom:6px}
.bar-w{display:flex;flex-direction:column;align-items:center;min-width:14px}
.bar{width:9px;border-radius:2px 2px 0 0;background:var(--green);opacity:.75;position:relative}
.bar:hover{opacity:1}
.bar:hover::after{
  content:attr(data-v);position:absolute;top:-22px;left:50%;transform:translateX(-50%);
  background:#000;color:var(--text);padding:2px 5px;border-radius:4px;font-size:.6em;
  white-space:nowrap;font-family:var(--mono);border:1px solid var(--border);
}
.bar-label{font-size:.5em;color:var(--muted);margin-top:3px;transform:rotate(-45deg);white-space:nowrap}
.chart-hint{font-size:.68em;color:var(--muted);text-align:right;margin-bottom:14px}

.cmp-grid{display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-bottom:12px}
.cmp-box{padding:14px;border-radius:10px;text-align:center}
.cmp-manual{background:rgba(248,113,113,.08);border:1px solid rgba(248,113,113,.25)}
.cmp-smart{background:rgba(74,222,128,.08);border:1px solid rgba(74,222,128,.25)}
.cmp-box .lbl{font-size:.7em;text-transform:uppercase;color:var(--muted);margin-bottom:6px}
.cmp-box .num{font-family:var(--mono);font-size:1.5em;font-weight:600}
.cmp-manual .num{color:var(--red)}
.cmp-smart .num{color:var(--green)}
.saving{background:rgba(74,222,128,.1);border:1px solid rgba(74,222,128,.25);border-radius:10px;padding:12px;text-align:center;margin-bottom:12px}
.saving .num{font-family:var(--mono);font-size:1.8em;font-weight:600;color:var(--green)}
.saving .lbl{font-size:.75em;color:var(--muted);margin-top:2px}
.stat-row{display:grid;grid-template-columns:repeat(3,1fr);gap:8px}
.stat-item{background:var(--card2);border:1px solid var(--border);border-radius:8px;padding:10px;text-align:center}
.stat-item .num{font-family:var(--mono);font-weight:600;color:var(--green)}
.stat-item .lbl{font-size:.65em;color:var(--muted);margin-top:3px;text-transform:uppercase}

.links{display:flex;gap:8px;flex-wrap:wrap}
.links a{
  font-size:.8em;color:var(--text);text-decoration:none;background:#222;
  border:1px solid var(--border);padding:9px 14px;border-radius:7px;
}
.links a:hover{background:#2a2a2a}
.schema{font-family:var(--mono);font-size:.72em;color:var(--muted);padding:8px 0;border-bottom:1px solid var(--border)}
.schema:last-child{border-bottom:none}
.schema b{color:var(--text);display:block;margin-bottom:2px;font-size:1.05em}

footer{text-align:center;font-size:.7em;color:var(--muted);margin-top:6px}
</style>
</head>
<body>

<header>
  <h1>🌿 Irriga<span>Smart</span></h1>
  <div id="clock">—</div>
</header>

<div class="tabs">
  <button class="tab-btn active" onclick="showTab('overview',this)">Visão Geral</button>
  <button class="tab-btn" onclick="showTab('historico',this)">Histórico</button>
  <button class="tab-btn" onclick="showTab('irrigacao',this)">Irrigações</button>
  <button class="tab-btn" onclick="showTab('comparativo',this)">Comparativo</button>
  <button class="tab-btn" onclick="showTab('downloads',this)">Downloads</button>
</div>

<!-- ══ OVERVIEW ══ -->
<div class="tab-pane active" id="pane-overview">
  <div class="grid">
    <div class="box" id="bx-solo">
      <div class="label">Umidade Solo</div>
      <div class="val v-green" id="v-solo">—</div>
      <div class="sub">limiar <span id="v-limiar">—</span></div>
    </div>
    <div class="box">
      <div class="label">Bomba</div>
      <div class="val v-amber" id="v-pump">—</div>
      <div class="sub" id="v-pump-sub">—</div>
    </div>
    <div class="box">
      <div class="label">Temperatura</div>
      <div class="val v-blue" id="v-temp">—</div>
      <div class="sub">DHT22</div>
    </div>
    <div class="box">
      <div class="label">Umidade Ar</div>
      <div class="val" id="v-ar">—</div>
      <div class="sub">DHT22</div>
    </div>
  </div>

  <section>
    <h2>Controle</h2>
    <div class="pump">
      <div class="pump-info">Status atual<b id="pump-status">—</b></div>
      <button class="btn-on" id="btn-ligar" onclick="ligar()">Ligar</button>
      <button class="btn-off" id="btn-desligar" onclick="desligar()" style="display:none">Desligar</button>
    </div>
    <div id="alertas"></div>
  </section>
</div>

<!-- ══ HISTÓRICO ══ -->
<div class="tab-pane" id="pane-historico">
  <section>
    <h2>Umidade do solo <span class="count-badge" id="hist-count">0 registros</span></h2>
    <div class="chart" id="chart-solo"></div>
    <div class="chart-hint">passe o mouse sobre as barras</div>
  </section>
  <section>
    <h2>Temperatura</h2>
    <div class="chart" id="chart-temp"></div>
  </section>
  <section>
    <h2>Umidade do ar</h2>
    <div class="chart" id="chart-ar"></div>
  </section>
  <section>
    <h2>Tabela de registros</h2>
    <div class="table-wrap"><table id="hist-table">
      <tr><th>Horário</th><th>Temp.</th><th>Umid. Ar</th><th>Solo</th></tr>
    </table></div>
  </section>
</div>

<!-- ══ IRRIGAÇÕES ══ -->
<div class="tab-pane" id="pane-irrigacao">
  <section>
    <h2>Log de irrigações <span class="count-badge" id="irr-count">0 eventos</span></h2>
    <div id="irr-wrap"><div class="empty">Carregando…</div></div>
  </section>
</div>

<!-- ══ COMPARATIVO ══ -->
<div class="tab-pane" id="pane-comparativo">
  <section>
    <h2>Inteligente vs. Manual</h2>
    <div class="cmp-grid">
      <div class="cmp-box cmp-manual">
        <div class="lbl">Manual estimado</div>
        <div class="num" id="cmp-manual">—</div>
      </div>
      <div class="cmp-box cmp-smart">
        <div class="lbl">IrrigaSmart</div>
        <div class="num" id="cmp-smart">—</div>
      </div>
    </div>
    <div class="saving">
      <div class="num" id="cmp-econ">—</div>
      <div class="lbl">litros economizados</div>
    </div>
    <div class="stat-row">
      <div class="stat-item"><div class="num" id="st-dias">—</div><div class="lbl">dias</div></div>
      <div class="stat-item"><div class="num" id="st-acion">—</div><div class="lbl">acionamentos</div></div>
      <div class="stat-item"><div class="num" id="st-ef">—</div><div class="lbl">eficiência</div></div>
    </div>
  </section>
</div>

<!-- ══ DOWNLOADS ══ -->
<div class="tab-pane" id="pane-downloads">
  <section>
    <h2>Baixar dados em CSV</h2>
    <div class="links" style="margin-bottom:16px">
      <a href="/download/historico">📈 historico.csv</a>
      <a href="/download/eventos">💧 eventos.csv</a>
      <a href="/download/stats">📊 stats.csv</a>
    </div>
    <div class="schema"><b>historico.csv</b>horario, temperatura, umidadeAr, umidadeSolo</div>
    <div class="schema"><b>eventos.csv</b>horario, duracao_s, umidadeAntes, umidadeDepois, automatica</div>
    <div class="schema"><b>stats.csv</b>leituras, acionamentos, tempoBombaMs</div>
  </section>
</div>

<footer>CONNEPI 2026 · Recife – PE</footer>

<script>
function showTab(id, btn){
  document.querySelectorAll('.tab-pane').forEach(p=>p.classList.remove('active'));
  document.querySelectorAll('.tab-btn').forEach(b=>b.classList.remove('active'));
  document.getElementById('pane-'+id).classList.add('active');
  btn.classList.add('active');
  if(id==='historico') carregarHistorico();
  if(id==='irrigacao') carregarIrrigacao();
  if(id==='comparativo') carregarEstatisticas();
}

function atualizarRelogio(){
  document.getElementById('clock').textContent =
    new Date().toLocaleTimeString('pt-BR',{hour:'2-digit',minute:'2-digit',second:'2-digit'});
}
setInterval(atualizarRelogio,1000); atualizarRelogio();

async function fetchDados(){
  try{
    const r = await fetch('/api/dados');
    const d = await r.json();

    document.getElementById('v-solo').textContent = d.umidadeSolo.toFixed(1)+'%';
    document.getElementById('v-limiar').textContent = d.limiar.toFixed(1)+'%';

    const vTemp = document.getElementById('v-temp');
    const vAr = document.getElementById('v-ar');
    if(d.dhtOk){
      vTemp.textContent = d.temperatura.toFixed(1)+'°C';
      vTemp.className = 'val v-blue';
      vAr.textContent = d.umidadeAr.toFixed(1)+'%';
      vAr.className = 'val';
    } else {
      vTemp.textContent = '—';
      vTemp.className = 'val v-red';
      vAr.textContent = '—';
      vAr.className = 'val v-red';
    }

    document.getElementById('bx-solo').style.borderColor = (d.umidadeSolo < d.limiar) ? 'var(--red)' : 'var(--border)';

    const vp = document.getElementById('v-pump');
    vp.textContent = d.bombaLigada ? 'ON' : 'OFF';
    vp.className = 'val ' + (d.bombaLigada ? 'v-red' : 'v-amber');
    document.getElementById('v-pump-sub').textContent = d.bombaLigada ? 'irrigando' : 'standby';

    document.getElementById('pump-status').textContent = d.bombaLigada ? 'LIGADA' : 'Desligada';
    document.getElementById('btn-ligar').style.display = d.bombaLigada ? 'none' : 'inline-block';
    document.getElementById('btn-desligar').style.display = d.bombaLigada ? 'inline-block' : 'none';

    const ab = document.getElementById('alertas');
    ab.innerHTML = '';
    if(!d.dhtOk) ab.innerHTML += '<div class="alert alert-temp">🔌 DHT22 sem resposta — verifique a conexão do sensor</div>';
    if(d.bloquadoPorTemperatura) ab.innerHTML += '<div class="alert alert-temp">🌡 Bloqueada — temperatura crítica</div>';
    if(d.reducaoPorHumidade) ab.innerHTML += '<div class="alert alert-hum">💨 Limiar reduzido — ar muito úmido</div>';
    if(!d.bloquadoPorTemperatura && !d.reducaoPorHumidade && d.dhtOk) ab.innerHTML = '<div class="alert alert-ok">✓ Condições normais</div>';
  }catch(e){console.error(e)}
}

async function ligar(){ await fetch('/api/bomba/ligar'); fetchDados(); }
async function desligar(){ await fetch('/api/bomba/desligar'); fetchDados(); }

function renderChart(id, readings, key, unit){
  const el = document.getElementById(id);
  if(!readings.length){ el.innerHTML='<div class="empty">Sem dados ainda.</div>'; return; }
  const vals = readings.map(r=>r[key]);
  const max = Math.max(...vals,1);
  el.innerHTML = readings.slice(-60).map(r=>{
    const h = Math.max(3,(r[key]/max)*100);
    return '<div class="bar-w"><div class="bar" style="height:'+h+'px" data-v="'+r[key].toFixed(1)+unit+'"></div><div class="bar-label">'+r.time+'</div></div>';
  }).join('');
}

async function carregarHistorico(){
  try{
    const r = await fetch('/api/historico');
    const d = await r.json();
    document.getElementById('hist-count').textContent = d.count+' registros';
    renderChart('chart-solo', d.readings, 'umidadeSolo', '%');
    renderChart('chart-temp', d.readings, 'temperatura', '°C');
    renderChart('chart-ar', d.readings, 'umidadeAr', '%');

    const tbl = document.getElementById('hist-table');
    if(!d.readings.length){
      tbl.innerHTML = '<tr><th>Horário</th><th>Temp.</th><th>Umid. Ar</th><th>Solo</th></tr><tr><td colspan="4" class="empty">Sem registros.</td></tr>';
      return;
    }
    const rows = [...d.readings].reverse().map(r=>
      '<tr><td>'+r.time+'</td><td>'+r.temperatura.toFixed(1)+'°C</td><td>'+r.umidadeAr.toFixed(1)+'%</td><td>'+r.umidadeSolo.toFixed(1)+'%</td></tr>'
    ).join('');
    tbl.innerHTML = '<tr><th>Horário</th><th>Temp.</th><th>Umid. Ar</th><th>Solo</th></tr>'+rows;
  }catch(e){console.error(e)}
}

async function carregarIrrigacao(){
  try{
    const r = await fetch('/api/irrigacao');
    const d = await r.json();
    document.getElementById('irr-count').textContent = d.count+' eventos';
    const wrap = document.getElementById('irr-wrap');
    if(!d.events.length){ wrap.innerHTML = '<div class="empty">Nenhuma irrigação registrada ainda.</div>'; return; }
    const rows = [...d.events].reverse().map(e=>
      '<tr><td>'+e.time+'</td><td>'+e.duracao_s+'s</td><td>'+e.umidadeAntes.toFixed(1)+'%</td><td>'+e.umidadeDepois.toFixed(1)+'%</td><td><span class="'+(e.automatica?'badge-auto':'badge-manual')+'">'+(e.automatica?'Auto':'Manual')+'</span></td></tr>'
    ).join('');
    wrap.innerHTML = '<div class="table-wrap"><table><tr><th>Horário</th><th>Duração</th><th>Antes</th><th>Depois</th><th>Tipo</th></tr>'+rows+'</table></div>';
  }catch(e){console.error(e)}
}

async function carregarEstatisticas(){
  try{
    const r = await fetch('/api/estatisticas');
    const d = await r.json();
    document.getElementById('cmp-manual').textContent = d.litrosManual.toFixed(0)+' L';
    document.getElementById('cmp-smart').textContent = d.litrosInteligente.toFixed(0)+' L';
    document.getElementById('cmp-econ').textContent = d.economiaLitros.toFixed(1)+' L';
    document.getElementById('st-dias').textContent = d.diasMonitorados.toFixed(2);
    document.getElementById('st-acion').textContent = d.acionamentos;
    document.getElementById('st-ef').textContent = d.eficiencia.toFixed(1)+'%';
  }catch(e){console.error(e)}
}

fetchDados();
setInterval(fetchDados, 2000);
</script>
</body>
</html>
)rawhtml";

#endif