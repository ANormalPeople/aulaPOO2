from moviepy.editor import VideoFileClip
# Carrega o vídeo com áudio
while True:
    video = VideoFileClip("C:\\Users\\Windows\\OneDrive\\Imagens\\Imagens da Câmera\\mew.mp4")
    # Reproduz o vídeo com áudio
    video.preview()