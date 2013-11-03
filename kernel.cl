__kernel void filter2(__read_only image2d_t imageIn,
		     __write_only image2d_t imageOut,
		     sampler_t sampler,
		     int width,
		     int height
		     )
{
    int2 image_coord = (int2){get_global_id(0), get_global_id(1)};
    float4 out_color = (float4){0.0f, 0.0f, 0.0f, 0.0f};
    out_color = read_imagef(imageIn, sampler, image_coord);
    write_imagef(imageOut, image_coord, out_color);
}
		     
