# Conversion of a video using ppm_worker.

  using ffmpeg split the video into its individual frames this command below will generate a frames_folder with all the video frames;

  """ffmpeg -i input_video.mp4 frames_folder/frame_%04d.ppm"""

## Using the ppm_worker on the frames(linux)(bash)
"""
THRESHOLD=100  
for input_file in frames_folder/*.ppm; do
    base_name=$(basename "$input_file")
    output_file="processed_frames_folder/$base_name"
    ./code/ppm_worker "$input_file" "$output_file" -E "$THRESHOLD"
done
"""
## Using the ppm_worker on the frames(windows)(powershell):
"""
$THRESHOLD = 100 
# Get list of .ppm files and pipe them to a loop
Get-ChildItem -Path "frames_folder" -Filter "*.ppm" | ForEach-Object {
    $input_file = $_.FullName
    $base_name = $_.Name
    $output_file = "processed_frames_folder\$base_name"
    & ".\code\ppm_worker" $input_file $output_file -E $THRESHOLD
}
"""

## FFMPEG command to convert the frames back into video
ffmpeg -framerate 30 -i processed_frames_folder/frame_%04d.ppm -c:v libx264 -pix_fmt yuv420p output_video.mp4
