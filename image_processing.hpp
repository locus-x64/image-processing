#ifndef IMAGE_PROCESS_H
#define IMAGE_PROCESS_H

#include "SimpleImage.hpp"

/**
 * Creates an image that is the negative of the original.
 * (white to black) becomes (black to white).
 * @param  image A reference to an image that is not altered.
 * @return The new negative version of the image.
 */
SimpleImage invert(const SimpleImage &image);

/**
 * Creates an image that is essentially upside-down, as if it were rotated on a horizontal axis.
 * @param image A reference to the original image that is not altered.
 * @return The new vertically flipped image.
 */
SimpleImage vert_flip(const SimpleImage &image);

/**
 * Creates an image that is mirrored, as if it were rotated on a vertical axis.
 * @param image A reference to the original image that is not altered.
 * @return The new image that is flipped.
 */
SimpleImage horiz_flip(const SimpleImage &image);

/**
 * Creates an image that is rotated 90 degrees clockwise.
 * @param image A reference to the original image that is not altered.
 * @return The new rotated image.
 */
SimpleImage rotate(const SimpleImage &image); 

/**
 * Creates an image that is resized by a scaling factor.
 * @param image A reference to the original image that is not altered.
 * @param scalefactor If this factor is &gt; 1, the image is enlarged by the factor.
 *				If it is &lt; 1, the image is reduced by the inverse of the factor.
 * @return The new scaled image.
 */
SimpleImage scale(const SimpleImage &image, double scalefactor);
			
/**
 * Given the correct input from the user, takes an original image and converts
 * it as specifed.
 * @param argc The number of arguments provided by the user (plus one for the name of the executable file).
 * @param argv An array of string instructions that are accepted in the following order:
 *	<ul>
 *		<li>The name of the file that contains the original image.</li>
 *		<li>The name of the file that will contain the converted image.</li>
 *		<li>The name of the task: one of the following:<ul>
 *				<li>invert</li>
 *				<li>horizontalFlip</li>
 *				<li>verticalFlip</li>
 *				<li>makeAscii</li>
 *				<li>rotate</li>
 *				<li>scale &lt;scalefactor&gt;</li>	
 *			</ul></li>
 *		<li>If scale is the task, then it must be followed by a number.</li>
 *	</ul>
 * @return 0 to indicate a successful completion.
 */
int main(int argc, char* argv[]); 

#endif
