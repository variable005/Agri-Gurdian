from fastapi import FastAPI, Request
from fastapi.responses import HTMLResponse, FileResponse
from fastapi.middleware.cors import CORSMiddleware
import requests
import uvicorn

app = FastAPI()

# This handles the browser security (CORS)
app.add_middleware(CORSMiddleware, allow_origins=["*"], allow_methods=["*"], allow_headers=["*"])

# LM Studio Local Server URL
LM_STUDIO_URL = "http://127.0.0.1:1234/v1/chat/completions"

@app.get("/")
async def serve_index():
    return FileResponse("index.html")

@app.post("/proxy-ai")
async def proxy_ai(request: Request):
    payload = await request.json()
    try:
        # Forwards the request to LM Studio
        response = requests.post(LM_STUDIO_URL, json=payload, timeout=60)
        return response.json()
    except Exception as e:
        return {"error": str(e)}

if __name__ == "__main__":
    print("🚀 Agri-Guardian Bridge is running at http://127.0.0.1:8000")
    uvicorn.run(app, host="127.0.0.1", port=8000)
