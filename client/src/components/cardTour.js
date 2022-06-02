import React from "react";
import {
    MDBCard,
    MDBCardBody,
    MDBCardTitle,
    MDBCardText,
    MDBCardImage,
    MDBCardGroup,
    MDBBtn,
    MDBIcon,
    MDBTooltip,
} from "mdb-react-ui-kit";

import { Link } from "react-router-dom";

const CardTour = ({ _id, title, description, name, creator, tags, imageFile }) => {


    //to control string length
    const excerpt = (str) => {
        if (str.length > 45) {
            str = str.substring(0, 45) + " ...";
        }
        return str;
    };

    

    return (
        <MDBCardGroup className="mb-5">
            <MDBCard className="h-100 mt-2 d-sm-flex" style={{ maxWidth: "20rem" }}>
                <MDBCardImage
                    src={imageFile}
                    alt={title}
                    position="top"
                    style={{ maxWidth: "100%", height: "180px" }}
                />
                <div className="top-left">{name}</div>
                <span className="text-start tag-card" >
                    {tags.map((tag, idx) => (
                        <Link key={idx} to={`/tours/tag/${tag}`}> #{tag}</Link>
                    ))}
                </span>

                <MDBCardBody>
                    <MDBCardTitle className="text-start">{title}</MDBCardTitle>
                    <MDBCardText className="text-start">
                        {/*excerpt is used to control length of string  */}
                        {excerpt(description)}
                        <Link to={`/tour/${_id}`}>Read More</Link>

                    </MDBCardText>
                </MDBCardBody>




            </MDBCard>
        </MDBCardGroup>
    )
}

export default CardTour;